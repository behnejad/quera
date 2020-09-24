import React, { useState, useContext } from 'react';
import {AuthContext} from '../context/auth-context';

const Register = props => {
  const { setUser } = useContext(AuthContext);
  const [error, setError] = useState('')
  const onSubmit = async (e) => {
    e.preventDefault()
    try {
      await fetch('http://localhost:8989/api/register', {
        method: 'POST',
        body: JSON.stringify({
          username: e.target.elements[0].value,
          password: e.target.elements[1].value
        })
      })
      .then(response => response.json())
      .then(data => {
        setUser(data.user)
      })
      .catch(e => setError(e.message))
    } catch (e) {
      setError(e.message)
    }
  }
  return (
    <div className="account-form">
      <h2>Sign up</h2>
      <div className="error-message" data-testid="error-message">{error}</div>
      <form onSubmit={onSubmit}>
        <input type="text" id="username" placeholder="Enter username" />
        <input type="password" id="password" placeholder="Enter password" />
        <button type="submit" data-testid="register-btn">
          Register
        </button>
      </form>
      <button className="link" onClick={props.changePage}>
        Already have an account? Log In
      </button>
    </div>
  )
};

export default Register;
