An example plugin showing how to use native functions to move an actor with collision checking.

This probably isn't as optimal as it gets, but its better than using the default Move Actor event every frame. Many built in events use GBVM heavily to fetch and prepare values, making their use in an actors On Update event unviable. You can have about 3-4 actors moving at once and collion checking against walls without slowdown using this method. 

References: 

GB Studio source: https://github.com/chrismaltby/gb-studio/

Guds actor ID: https://github.com/mikeleisz/gud_gbs_plugins/tree/main/Store%20Actor%20ID%20In%20Variable

The internal function used: https://github.com/chrismaltby/gb-studio/blob/e122e9ab5dac67ce413117f0c84bb5e42913280e/appData/src/gb/src/core/actor.c#L387


Thanks to Tomo on the Discord (and many others) for the example on how to correctly get variable aliases, locals must be grabbed this way to prevent a bug

```js
export const compile = (input, helpers) => {
  const {_stackPushReference, _setVariable, _callNative, _stackPop, getActorIndex, getVariableAlias } = helpers;
  const actorIndex = getActorIndex(input.actorId);
  const { precompileScriptValue, optimiseScriptValue } = scriptValueHelpers;

  // Get & push the value for target
  const [typeTarget] = precompileScriptValue(optimiseScriptValue(input.target));
  // Check if the passed target value is a number or variable
  if(typeTarget[0].type === "number") {
    // It was a number, so we push to stack as constant
    _stackPushConst(typeTarget[0].value);
  } else if(typeTarget[0].type === "variable") {
    // It was a variable, so we push to stack as variable
    const variableAlias = getVariableAlias(typeTarget[0].value);
    _stackPush(variableAlias);
  }

  // why pushing as reference?
  //_stackPushReference(input.target);

  _stackPushReference(actorIndex);
  _callNative("beugs_actor_move_bounce");
  _setVariable(input.target, ".ARG1");
  _stackPop(1);
};
```
