/*
     The fast pipe operator -> places the primary input in the FIRST argument position
     Let's look at its use with Belt's List.map in a couple scenarios
 */
module FastPipe = {
  /* Recall Belt's List.map signature
     let map: (list('a), 'a => 'b) => list('b); */

  let add5 = n => n + 5; /* callback func */
  /* The list of integers are inserted as the first argument */
  let listPlus5 = [1, 2, 3, 4, 5]->Belt.List.map(add5); /* [6,7,8,9,10] */

  /* Common ReasonReact recipe for mapping over React elements */
  let someMappedReasonElements =
    ["Text1", "Text2", "Text3"]
    ->Belt.List.map(text => <div> {ReasonReact.string(text)} </div>)
    ->Array.of_list
    ->ReasonReact.array;
};
