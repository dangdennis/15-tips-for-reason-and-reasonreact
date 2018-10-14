/*
 All functions in Reason are automatically curried
 Let's use List.map as an example
 Function signature: let map: ('a => 'b, list('a)) => list('b);
 */

let add5 = n => n + 5; /* callback func */
let add5ToList = List.map(add5);

let list = [1,2,3,4,5];
let listPlus5 = add5ToList(list); /* [6,7,8,9,10] */

/* Post-Bucklescript compilation
function add5(n) {
  return n + 5 | 0;
}

function add5ToList(param) {
  return List.map(add5, param);
}
*/



