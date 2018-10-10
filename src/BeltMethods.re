open Belt
/* This is a variant of type animal */
type animal =
  | Cat
  | Dog;

/* This is a record of type cat */
type cat = {
  name: string,
  species: animal /* animal can be Cat or Dog */
  /* color: string */
};

let someCat = {name: "Fooz", species: Cat};

let someDog = {name: "Buzz", species: Dog};

/* let someHorse = {
     name: "Neeiighbor",
     species: Horse
   };
   */

let listOfAnimals = [
  {name: "Persian", species: Cat},
  {name: "Siamese", species: Cat},
  {name: "Scottish Fold", species: Cat},
  {name: "Bombay", species: Cat},
  {name: "Corgi", species: Dog},
];

let animalNamesOnly = List.map(listOfAnimals, animal => animal.name);
/* let catNamesOnly = List.map(animal => animal.name, catsOnly); */
/* let catNamesOnly: list(string) = ["Persian", "Siamese", "Scottish Fold", "Bombay"]; */

/* let dogsOnly = List.filter(animal => animal.species === Dog, listOfAnimals); */
/* let dogsOnly: list(cat) = [{name: "Corgi", species: Dog}]; */