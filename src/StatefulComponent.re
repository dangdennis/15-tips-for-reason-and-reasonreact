/* Like proptypes, you define your state type */
type state = {counter: int};

/* Define a Redux-like action variant here */
type action =
  | Count(int);

/* Define the reducer component */
let component = ReasonReact.reducerComponent("SomeStatefulComponent");

let make = _children => {
  ...component,
  /* Define a reducer method that states action and state */
  initialState: () => {counter: 0},
  reducer: (action, state) =>
    /* Do pattern matching of all defined actions
       to Update (Reason's setState and action creator) */
    switch (action) {
    | Count(int) => ReasonReact.Update({counter: int + state.counter})
    },
  render: self =>
    <div>
      <p>
        {ReasonReact.string("Count: " ++ string_of_int(self.state.counter))}
      </p>
      <button onClick={_event => self.send(Count(5))}>
        {ReasonReact.string("+5")}
      </button>
    </div>,
};