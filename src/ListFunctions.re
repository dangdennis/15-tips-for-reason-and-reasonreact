/* This is a variant of type animal */
type animal =
  | Cat
  | Dog;

/* This is a record of type cat */
type cat = {
  name: string,
  species: animal /* animal can be Cat or Dog */
};

let someCat = {name: "Fooz", species: Cat};

let someDog = {name: "Buzz", species: Dog};

/* let someHorse = {
  name: "Neeiighbor",
  species: Horse 
};
*/

let listOfCats = [
  {name: "Persian", species: Cat},
  {name: "Siamese", species: Cat},
  {name: "Scottish Fold", species: Cat},
  {name: "Bombay", species: Cat},
  {name: "Corgi", species: Dog},
];