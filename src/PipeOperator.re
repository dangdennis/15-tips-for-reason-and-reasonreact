/*
     The pipe operator |> places the primary input in the LAST argument position
     Let's look at its use with List.map in a couple scenarios
 */
module Pipe = {
  let add5 = n => n + 5; /* callback func */
  let listPlus5 = [1, 2, 3, 4, 5] |> List.map(add5); /* [6,7,8,9,10] */

  /* Common ReasonReact recipe for mapping over React elements */
  let someMappedReasonElements =
    ["Text1", "Text2", "Text3"]
    |> List.map(text => <div> {ReasonReact.string(text)} </div>)
    |> Array.of_list
    |> ReasonReact.array; /* HTML: <div>Text1></div><div>Text2</div><div>Text3</div> */
};