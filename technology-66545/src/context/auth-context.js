import React, { createContext, useContext, useState } from 'react';

export const AuthContext = createContext({
    user: false,
    setUser: (username) => {
        console.log(username)
    },
    logout: (e) => {
        console.log(e)
    }
});

export const AuthProvider = (props) => {
    const context = useContext(AuthContext);
    const [user, setUser] = useState(context.user);
    const logout = () => {
        setUser(false)
    }
    return (
        <AuthContext.Provider value={{
            user: user,
            logout: logout,
            setUser: setUser
        }}>
            {props.children}
        </AuthContext.Provider>
    )
}