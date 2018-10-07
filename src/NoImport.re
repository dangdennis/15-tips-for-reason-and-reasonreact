/* SecondComponent.js */

let component = ReasonReact.statelessComponent("AnotherRandomComponent");

let make = (_children) => {
  ...component,
  render: _self =>
  <div>
    <div> {ReasonReact.string("Your second ReasonReact component")} </div>
    <FileName />
    /* <FirstComponent /> */
  </div>
};