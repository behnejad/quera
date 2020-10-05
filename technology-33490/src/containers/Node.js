import React from 'react';
import { Component } from 'react';
import { connect } from 'react-redux';
import * as actions from '../actions';

export class Node extends Component {
  renderChild = childId => {
    const { id } = this.props;
    return <ConnectedNode key={childId} id={childId} parentId={id} />;
  };

  addChild = childId => {
    this.props.addChild(this.props.id, childId);
  };
  addChildFile = () => {
    const newFile = this.props.createNode('file');
    this.addChild(newFile.nodeId);
  };
  addChildFolder = () => {
    const newFolder = this.props.createNode('folder');
    this.addChild(newFolder.nodeId);
  };
  removeNode = () => {
    this.props.deleteNode(this.props.id);
    if (this.props.parentId !== undefined) {
      this.props.removeChild(this.props.parentId, this.props.id);
    }
  };
  editCurrentNode = () => {
    this.props.setEditNode(this.props.id);
  };

  render() {
    const { id, counter, parentId, childIds, name, isDir } = this.props;
    if (isDir) {
      return (
        <li key={counter}>
          <label htmlFor={name.replace(' ', '_')}>
            {name}
            {
              <>
                <span
                  id={`remove_${id}`}
                  className="action-button"
                  onClick={this.removeNode}>
                  ×
                </span>
                <span
                  id={`add_child_file_${id}`}
                  className="action-button"
                  onClick={this.addChildFile}>
                  📄
                </span>
                <span
                  id={`add_child_folder_${id}`}
                  className="action-button"
                  onClick={this.addChildFolder}>
                  📂
                </span>
              </>
            }
          </label>
          <input type="checkbox" id={toString(id).replace(' ', '_')} />
          <ol>{childIds.map(this.renderChild)}</ol>
        </li>
      );
    } else {
      return (
        <li key={counter} className="file">
          <a
            id={`select_current_edit_${id}`}
            className="file-name"
            onClick={this.editCurrentNode}>
            {name}
          </a>
          {typeof parentId !== 'undefined' && (
            <span
              onClick={this.removeNode}
              id={`remove_${id}`}
              className="action-button">
              ×
            </span>
          )}
        </li>
      );
    }
  }
}

function mapStateToProps(state, ownProps) {
  return {
    editNode: state.editNode,
    ...state.nodes[ownProps.id]
  };
}

const ConnectedNode = connect(
  mapStateToProps,
  actions
)(Node);
export default ConnectedNode;
