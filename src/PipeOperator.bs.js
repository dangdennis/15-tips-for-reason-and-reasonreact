// Generated by BUCKLESCRIPT VERSION 4.0.6, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var React = require("react");

function add5(n) {
  return n + 5 | 0;
}

var listPlus5 = List.map(add5, /* :: */[
      1,
      /* :: */[
        2,
        /* :: */[
          3,
          /* :: */[
            4,
            /* :: */[
              5,
              /* [] */0
            ]
          ]
        ]
      ]
    ]);

var someMappedReasonElements = $$Array.of_list(List.map((function (text) {
            return React.createElement("div", undefined, text);
          }), /* :: */[
          "Text1",
          /* :: */[
            "Text2",
            /* :: */[
              "Text3",
              /* [] */0
            ]
          ]
        ]));

var Pipe = /* module */[
  /* add5 */add5,
  /* listPlus5 */listPlus5,
  /* someMappedReasonElements */someMappedReasonElements
];

exports.Pipe = Pipe;
/* listPlus5 Not a pure module */
