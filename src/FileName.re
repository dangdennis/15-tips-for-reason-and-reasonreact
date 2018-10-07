/* FirstComponent.js */

let component = ReasonReact.statelessComponent("RandomComponent");

let make = (_children) => {
  ...component,
  render: _self =>
    <div> {ReasonReact.string("Your first ReasonReact component")} </div>,
};