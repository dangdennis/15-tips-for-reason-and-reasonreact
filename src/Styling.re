/* 
1. Use stylesheets
BuckleScript provides escape hatches. 
You can run native Javascript code with [%bs.raw {| CODE GOES BETWEEN HERE |}] 
*/
[%bs.raw {|require('./index.css')|}];

/* 2. Use inline styles */
let styles = ReactDOMRe.Style.make(~backgroundColor="peach", ~width="500px", ());
<div style=styles />;