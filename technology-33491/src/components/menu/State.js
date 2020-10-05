import React from 'react';
import './State.css';

export class State extends React.PureComponent {
  render() {
    let className;
    if (this.props.win) {
      className = 'win';
    } else if (this.props.turn) {
      className = 'turn';
    }
    if (this.props.person === 1) className += '-1';
    if (this.props.person === 2) className += '-2';
    className += ' state';
    return <div className={className} />;
  }
}
