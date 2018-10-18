open Belt;

let fakeRealApi = "https://jsonplaceholder.typicode.com/posts";

type post = {
  userId: int,
  id: int,
  title: string,
  body: string,
};
type dog = string;

type state =
  | Loading
  | Error
  | LoadedPosts(array(post));

type action =
  | PostsFetch
  | PostsFailedToFetch
  | PostsFetched(array(post));

module Decode = {
  let post = json =>
    Json.Decode.{
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
      ReasonReact.UpdateWithSideEffects(
        Loading,
        (
          self =>
            Js.Promise.(
              Fetch.fetch(fakeRealApi)
              |> then_(Fetch.Response.json)
              |> then_(json => {
                   Js.log(json);
                   json
                   |> Decode.posts
                   |> (posts => self.send(PostsFetched(posts)) |> resolve);
                 })
              |> catch(_err =>
                   Js.Promise.resolve(self.send(PostsFailedToFetch))
                 )
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