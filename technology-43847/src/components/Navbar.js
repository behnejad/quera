import React, { useContext } from 'react';
import { makeStyles } from '@material-ui/core/styles';
import { AppBar, Toolbar, Typography, Button, IconButton, Menu, MenuItem } from '@material-ui/core';
import MenuIcon from '@material-ui/icons/Menu';
import SetLangoueg from '../contexts';

const useStyles = makeStyles(theme => ({
    root: {
        flexGrow: 1,
    },
    menuButton: {
        marginRight: theme.spacing(2),
    },
    title: {
        marginRight: "10px",
        marginLeft: "10px"
    },
    toolbar: {
        display: "flex",
        justifyContent: "space-between !important"
    },
    btn: {
        color: "white",
    }
}));


export default function Navbar() {
    const { words, changeToEnglish, changeToPersian } = useContext(SetLangoueg)
    const classes = useStyles();
    const [anchorEl, setAnchorEl] = React.useState(null);

    function handleClick(event) {
        setAnchorEl(event.currentTarget);
    }

    function handleClose() {
        setAnchorEl(null);
    }
    return (
        <div className={classes.root}>
            <AppBar position="static">
                <Toolbar className={classes.toolbar}>
                    <div>
                        <IconButton edge="start" className={classes.menuButton} color="inherit"
                            aria-label="menu">
                            <MenuIcon />
                        </IconButton>
                        <Button
                            id={"_home"}
                            className={classes.btn}>
                            <Typography variant="h6" className={classes.title}>
                                {words.home}
                            </Typography>
                        </Button>
                        <Button
                            id={"_events"}
                            className={classes.btn}>
                            <Typography variant="h6" className={classes.title}>
                                {words.events}
                            </Typography>
                        </Button>
                        <Button
                            id={"_about"}
                            className={classes.btn}>
                            <Typography variant="h6" className={classes.title}>
                                {words.aboutUs}
                            </Typography>
                        </Button>
                        <Button
                            id={"_contact"}
                            className={classes.btn}>
                            <Typography variant="h6" className={classes.title}>
                                {words.contactUs}
                            </Typography>
                        </Button>
                    </div>
                    <div>
                        <Button
                            aria-controls="simple-menu"
                            aria-haspopup="true"
                            onClick={handleClick}
                            className={classes.btn}
                            id={"_lan"}
                            color="inherit">
                            {words.language}
                        </Button>
                    </div>
                    <Menu
                        id="simple-menu"
                        anchorEl={anchorEl}
                        keepMounted
                        open={Boolean(anchorEl)}
                        onClose={handleClose}
                    >
                        <MenuItem
                            id={"_changeToPersian"}
                            onClick={changeToPersian}
                        >
                            فارسی
                    </MenuItem>
                        <MenuItem
                            id={"_changeToEnglish"}
                            onClick={changeToEnglish}
                        >
                            English
                    </MenuItem>
                    </Menu>
                </Toolbar>
            </AppBar>
        </div>
    );


};
