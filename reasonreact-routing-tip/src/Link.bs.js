// Generated by BUCKLESCRIPT VERSION 4.0.6, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("Link");

function handleClick(href, $$event) {
  if ($$event.defaultPrevented) {
    return 0;
  } else {
    $$event.preventDefault();
    console.log(href);
    return ReasonReact.Router[/* push */0](href);
  }
}

function make(href, children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              return ReactDOMRe.createElementVariadic("a", {
                          href: href,
                          onClick: Curry._1(self[/* handle */0], (function ($$event, _) {
                                  return handleClick(href, $$event);
                                }))
                        }, children);
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.handleClick = handleClick;
exports.make = make;
/* component Not a pure module */
