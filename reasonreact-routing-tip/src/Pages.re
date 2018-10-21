let str = ReasonReact.string;

type route =
  | Home
  | Page1
  | Page2
  | Page3
  | Page4
  | WildCardPage(string)
  | NotFound;

type state = {route};

type action =
  | ChangeRoute(route);

let reducer = (action, _state) =>
  switch (action) {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };

let urlToRoute = (url: ReasonReact.Router.url) =>
  switch (url.path) {
  | [""] 
  | []
  | ["/"] => Home
  | ["page1"] => Page1
  | ["page2"] => Page2
  | ["page3"] => Page3
  | ["nested", "page4"] => Page4
  | ["auth", wildCard] => WildCardPage(wildCard)
  | _ => NotFound
  };

let component = ReasonReact.reducerComponent("App");

let make = _children => {
  ...component,
  reducer,
  initialState: () => {route: Home},
  didMount: self => {
    let watchId =
      ReasonReact.Router.watchUrl(url =>
        self.send(ChangeRoute(url |> urlToRoute))
      );
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watchId));
  },
  render: self =>
    <div>
      <ul>
        <li> <Link href="/"> {str("Home")} </Link> </li>
        <li> <Link href="/page1"> {str("Page 1")} </Link> </li>
        <li> <Link href="/page2"> {str("Page 2")} </Link> </li>
        <li> <Link href="/page3"> {str("Page 3")} </Link> </li>
        <li> <Link href="/nested/page4"> {str("Nested Page")} </Link></li>
        <li> <Link href="/auth/*"> {str("Wild Card Auth Page")} </Link> </li>
      </ul>
      <div>
        {
          switch (self.state.route) {
          | Home =>
          <h1>{str("You've reached the home page")}</h1>
          | Page1 =>
          <h1>{str("You've reached page 1")}</h1>
          | Page2 =>
          <h1>{str("You've reached page 2")}</h1>
          | Page3 =>
            <h1>{str("You've reached page 3")}</h1>
          | Page4 =>
            <h1>{str("You've reached page 4")}</h1>
          | WildCardPage(id) =>
          <h1>{str("You've reached auth wild card: " ++ id  )}</h1>
          | NotFound =>
            <h1>{str("404 Page")}</h1>
          }
        }
      </div>
    </div>,
};