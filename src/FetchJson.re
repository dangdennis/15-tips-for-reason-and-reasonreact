/* Using Belt API for familiarity */
open Belt;

/* Will return an array of posts */
let fakeRealApi = "https://jsonplaceholder.typicode.com/posts";

/* Defining types for the expected posts */
type post = {
  userId: int,
  id: int,
  title: string,
  body: string,
};

/* Defining all state */
type state =
  | Loading
  | Error
  | LoadedPosts(array(post)); /* Pattern matching state too?! */

/* Like in Redux, there's 3 phases of an HTTP request */
/* Fetching, Fetched, and Failed */
type action =
  | PostsFetch
  | PostsFailedToFetch
  | PostsFetched(array(post));

/* Bs-json provides an API to encode, decode, and even compose
     JSON into Reason-compatible types
   */

/* Common practice to wrap your decoding functions into a local module */
module Decode = {
  let post = json =>
    /* We're creating a custom decoder here - reference bs-json docs */
    Json.Decode.{
      /* the field function establishes the type given a key in the json object */
      userId: json |> field("userId", int),
      id: json |> field("id", int),
      title: json |> field("title", string),
      body: json |> field("body", string),
    };
  let posts = Json.Decode.array(post);
};

let component = ReasonReact.reducerComponent("FetchExample");

let make = _children => {
  ...component,
  initialState: _state => Loading,
  reducer: (action, _state) =>
    switch (action) {
    | PostsFetch =>
      /* Notice the fetch is done within the reducer */
      ReasonReact.UpdateWithSideEffects(
        Loading,
        (
          self =>
            /* We wrap everything within a promise */
            Js.Promise.(
              Fetch.fetch(fakeRealApi)
              /* This looks sorta familiar right */
              |> then_(Fetch.Response.json)
              |> then_(json => {
                   Js.log(json);
                   json
                   /* We feed the json into the composed decoder */
                   |> Decode.posts
                   /* Now we kick off another action with the new payload */
                   |> (posts => self.send(PostsFetched(posts)) |> resolve);
                 })
              |> catch(_err =>
                   Js.Promise.resolve(self.send(PostsFailedToFetch))
                 )
              /* Ignore here because Reason expects a unit type */
              |> ignore
            )
        ),
      )
    | PostsFailedToFetch => ReasonReact.Update(Error)
    | PostsFetched(posts) => ReasonReact.Update(LoadedPosts(posts))
    },
  didMount: self => self.send(PostsFetch),
  render: self =>
    switch (self.state) {
    | Error => <div> {ReasonReact.string("An error occurred!")} </div>
    | Loading => <div> {ReasonReact.string("Loading...")} </div>
    | LoadedPosts(posts) =>
      <ul>
        {
          Array.map(posts, post =>
            <li key={string_of_int(post.id)}>
              {ReasonReact.string(post.title)}
            </li>
          )
          |> ReasonReact.array
        }
      </ul>
    },
};