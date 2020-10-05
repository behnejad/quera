export const CREATE_NODE = 'CREATE_NODE'
export const DELETE_NODE = 'DELETE_NODE'
export const EDIT_NODE = 'EDIT_NODE'
export const SET_EDIT_NODE = 'SET_EDIT_NODE'
export const ADD_CHILD = 'ADD_CHILD'
export const REMOVE_CHILD = 'REMOVE_CHILD'

let nextId = 0
export const createNode = (type) => {
  if (type == 'file') 
    return ({
      type: CREATE_NODE,
      nodeId: `new_${nextId++}`, 
      name: `file ${nextId}`,
      isDir: false,
    })
  else return ({
    type: CREATE_NODE,
    nodeId: `new_folder_${nextId++}`, 
    name: `folder ${nextId}`,
    isDir: true
  })
}

export const deleteNode = (nodeId) => ({
  type: DELETE_NODE,
  nodeId
})

export const editNode = (nodeId, content, name) => ({
  type: EDIT_NODE,
  nodeId,
  content,
  name
})

export const setEditNode = (nodeId) => ({
  type: SET_EDIT_NODE,
  nodeId
})

export const addChild = (nodeId, childId) => ({
  type: ADD_CHILD,
  nodeId,
  childId
})

export const removeChild = (nodeId, childId) => ({
  type: REMOVE_CHILD,
  nodeId,
  childId
})
