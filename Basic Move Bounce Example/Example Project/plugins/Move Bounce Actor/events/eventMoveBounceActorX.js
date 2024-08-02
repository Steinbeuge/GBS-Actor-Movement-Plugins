export const id = "BEUGS_MOVE_BOUNCE_X";
export const name = "Move Bounce Actor X";
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
		key: "target",
		label: "X Move Velocity",
		type: "variable",
		defaultValue: "LAST_VARIABLE",
	}
];  

export const compile = (input, helpers) => {
	const {_stackPush,_stackPushReference, _setVariable, _callNative, _stackPop, getActorIndex, getVariableAlias } = helpers;
    //const { precompileScriptValue, optimiseScriptValue } = scriptValueHelpers;

	const actorIndex = getActorIndex(input.actorId);
	_stackPush( getVariableAlias( input.target ) );
	_stackPushReference(actorIndex);
    _callNative("beugs_actor_move_bounce_x");
	_setVariable(input.target, ".ARG1");
	_stackPop(2);
};