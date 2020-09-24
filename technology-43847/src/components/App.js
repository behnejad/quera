import React, { Component } from 'react';
import Navbar from "./Navbar";
import LanguageProvider from './Language';

export default class App extends Component {
    render() {
        return (
            <LanguageProvider>
                <Navbar />
            </LanguageProvider>
        )

    }


}