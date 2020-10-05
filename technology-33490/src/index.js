import React from 'react'
import { render } from 'react-dom'
import { createStore } from 'redux'
import { Provider } from 'react-redux'
import reducer from './reducers'
import generateTree from './generateTree'
import Node from './containers/Node'
import Editor from './containers/Editor'

const tree = generateTree()
const store = createStore(reducer, {
  editNode: null,
  nodes: tree
})
render(
  <Provider store={store}>
    <div style={{width: '1040px'}}>
      <div style={{float: 'left'}}>
        <ol className="tree">
          <Node key={0} id={0} />
        </ol>
      </div>
      <div style={{float: 'right', padding: '25px', minWidth: '650px'}}>
        <Editor/>
      </div>
    </div>
  </Provider>,
  document.getElementById('root')
)
