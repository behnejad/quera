import React from 'react';
import { Component } from 'react';
import { connect } from 'react-redux';
import * as actions from '../actions';

export class Editor extends Component {
  content = React.createRef();
  name = React.createRef();
  handleSave = () => {
    this.props.editNode(
      this.props.editNodeVal.id,
      this.content.current.value,
      this.name.current.value
    );
    this.props.setEditNode(null);
  };
  render() {
    const { editNodeVal } = this.props;
    if (editNodeVal) {
      return (
        <div>
          <div>
            {' '}
            filename:
            <input
              ref={this.name}
              defaultValue={editNodeVal.name}
              className="file-name-input"
            />
          </div>
          <textarea
            ref={this.content}
            name="file_content"
            cols="65"
            rows="10"
            defaultValue={editNodeVal.content}
            className="file-content"
          />
          <div>
            <button onClick={this.handleSave} className="file-save-button">
              save
            </button>
          </div>
        </div>
      );
    } else {
      return <div>Select file for edit.</div>;
    }
  }
}

export default connect(
  state => ({
    editNodeVal: state.nodes[state.editNode]
  }),
  actions
)(Editor);
