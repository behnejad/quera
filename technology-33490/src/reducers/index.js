import {
  ADD_CHILD,
  REMOVE_CHILD,
  CREATE_NODE,
  DELETE_NODE,
  EDIT_NODE,
  SET_EDIT_NODE
} from '../actions';

const node = (state, action) => {
  switch (action.type) {
    case CREATE_NODE:
      return {
        id: action.nodeId,
        name: action.name,
        isDir: action.isDir,
        childIds: []
      };

    case ADD_CHILD: {
      return {
        ...state,
        childIds: [...state.childIds, action.childId]
      };
    }
    case REMOVE_CHILD: {
      return {
        ...state,
        childIds: state.childIds.filter(
          cId => String(cId) !== String(action.childId)
        )
      };
    }
    case EDIT_NODE: {
      return {
        ...state,
        content: action.content,
        name: action.name
      };
    }
    default:
      return state;
  }
};

let INITIAL_STATE = {
  editNode: null,
  nodes: {}
};

export default (state = INITIAL_STATE, action) => {
  if (typeof action.nodeId === 'undefined') {
    return state;
  }
  const nodeId = String(action.nodeId);
  if (action.type === SET_EDIT_NODE) {
    return {
      ...state,
      editNode: nodeId
    };
  }

  if (action.type === DELETE_NODE) {
    const nodeIdsToRemove = [nodeId];
    let newState = { ...state, nodes: { ...state.nodes } };
    nodeIdsToRemove.forEach((nodeId, i, arr) => {
      arr.push(...newState.nodes[nodeId].childIds);
      delete newState.nodes[nodeId];
    });
    return newState;
  }

  return {
    ...state,
    nodes: {
      ...state.nodes,
      [nodeId]: node(state.nodes[nodeId], action)
    }
  };
};
