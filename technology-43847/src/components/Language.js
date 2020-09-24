import React, { Component } from 'react';
import SetLangoueg from "../contexts/index";

export default class LanguageProvider extends Component {
    constructor(props) {
        super(props)
        this.state = {
            language: "Persian",
            words: {
                home: "خانه",
                events: "رویداد ها",
                aboutUs: "درباره ما",
                contactUs: "تماس با ما",
                language: "زبان"
            }
        }
    }
    changeToEnglish = () => {
        this.setState({
            language: "English",
            words: {
                home: "Home",
                events: "Events",
                aboutUs: "About Us",
                contactUs: "Contact Us",
                language: "Language"
            }
        })

    }
    changeToPersian = () => {
        this.setState({
            language: "Persian",
            words: {
                home: "خانه",
                events: "رویداد ها",
                aboutUs: "درباره ما",
                contactUs: "تماس با ما",
                language: "زبان"
            }
        })
    }
    render() {
        const { children } = this.props
        const { language, words } = this.state
        return (
            <SetLangoueg.Provider value={{
                language, words,
                changeToPersian: this.changeToPersian,
                changeToEnglish: this.changeToEnglish
            }}>
                {children}
            </SetLangoueg.Provider>

        )
    }

}
