/* ReasonElements.js */

let component = ReasonReact.statelessComponent("ReasonElements");

let make = _children => {
  ...component,
  render: _self => {
    let someListOfReactElements = [<div />, <div />, <div />];
    let someArrayOfReactElements = Array.of_list(someListOfReactElements);
    let isNull = true;

    <div>
      <div> {ReasonReact.string("Your third ReasonReact component")} </div>
      <div> {ReasonReact.array(someArrayOfReactElements)} </div>
      <div>
        {
          isNull ?
            ReasonReact.null : <p> {ReasonReact.string("Not null!")} </p>
        }
      </div>
    </div>;
  },
};