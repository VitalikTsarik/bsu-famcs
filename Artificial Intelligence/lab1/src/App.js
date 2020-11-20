import React from 'react';
import Tabs from "react-bootstrap/Tabs";
import Tab from "react-bootstrap/Tab";

import GamePage from 'components/GamePage';

import 'bootstrap/dist/css/bootstrap.min.css';
import './App.css'

const App = () => {
    return (
        <div className="vh-100 align-items-center justify-content-center">
            <Tabs
                className="align-items-center justify-content-center pt-3"
                defaultActiveKey="home"
            >
                <Tab eventKey="home" title="Home" tabClassName="pt-3">
                    <GamePage/>
                </Tab>
            </Tabs>
        </div>
    );
}

export default App;
