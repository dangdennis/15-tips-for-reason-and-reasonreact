/* Compiler error: You can convert a int to a string with string_of_int.*/
let integer10: int = 10; 

/* Proper use of typecast methods */
let string10: string = string_of_int(10);
let boolean10: bool = bool_of_string("true");
let float10: float = float_of_int(10);
let integer10Again: int = int_of_float(10.); 
let integer5: int = int_of_char('a'); /* Converts character to ASCII decimal equivalent */


