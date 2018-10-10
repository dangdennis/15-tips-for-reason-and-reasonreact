module ChildComponent = {
  let component = ReasonReact.statelessComponent("ChildComponent");
  /* You must declare your props as labeled arguments with the ~ symbol */
  /* If I don't, compile error: It only accepts 1 argument; here, it's called with more. */
  let make = (~randomTextProp, _children) => {
    ...component,
    render: _self => <p> {ReasonReact.string(randomTextProp)} </p>,
  };
};

module ParentComponent = {
  let component = ReasonReact.statelessComponent("ParentComponent");
  /* Compiler throws warnings if variables are unused */
  /* Ignore variables with _ */
  let make = _children => {
    ...component,
    render: _self =>
      /* Passing down some text as prop */
      <ChildComponent randomTextProp="Hey I'm a prop" />,
  };
};