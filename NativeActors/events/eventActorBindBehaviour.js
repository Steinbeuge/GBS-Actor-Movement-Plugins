export const id = "BEUGS_NATIVE_ACTORS";
export const name = "bind Behaviour to Actor";
export const groups = ["Beugs Plugs", "EVENT_GROUP_ACTOR"];
export const subGroups = {
	EVENT_GROUP_ACTOR: "EVENT_GROUP_VARIABLES",
	"Beugs Plugs": "ACTOR"
};

export const fields = [
	{
		key: "actorId",
		label: "Target Actor",
		type: "actor",
	},
    {
		key: "behaviourID",
		label: "Behaviour ID",
		type: "number",
		//defaultValue: "LAST_VARIABLE",
	},
	{
		key: "movx",
		label: "X Move Local",
		type: "variable",
		defaultValue: "LAST_VARIABLE",
	},
    {
		key: "movy",
		label: "Y Move Local",
		type: "variable",
		defaultValue: "LAST_VARIABLE",
	}
];  

export const compile = (input, helpers) => {
	const {_stackPushConst, _stackPushReference, _callNative, _stackPop, getActorIndex, getVariableAlias } = helpers;
    //const { precompileScriptValue, optimiseScriptValue } = scriptValueHelpers;

	const actorIndex = getActorIndex(input.actorId);
	_stackPushReference( getVariableAlias( input.movx ) );
    _stackPushReference( getVariableAlias( input.movy ) );
    _stackPushConst( input.behaviourID );
	_stackPushConst(actorIndex);
    _callNative("actor_assign_locals");
	_stackPop(4);
};