/* You can pattern match against a variety of data types:
  tuples, arrays, variants, strings, etc.
*/

/* Define a laptop variant */
type laptop =
  | Macbook
  | Chromebook
  | Surface(string);

/* Define a variable that holds constructor Macbook */
let mac = Macbook;

/* This is pattern switching -- it's just a switch comparing the argument
 against matching data */
switch (mac) {
| Macbook => "Your laptop runs on MacOS"
| Chromebook => "Your laptop runs on ChromeOS"
| Surface(os) => "Your laptop runs on " ++ os
| _ => "I don't think that's a prescribed laptop"
};