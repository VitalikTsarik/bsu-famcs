import React, {Component} from 'react';
import Button from "react-bootstrap/Button";
import Container from "react-bootstrap/Container";

import KnowledgeBase from 'components/KnowledgeBase';
import Select from 'components/Select';
import InferenceEngine, {mainTarget} from 'core/InferenceEngine';
import Finish from "./Finish";

class GamePage extends Component {
    componentWillMount() {
        this.initState();
    }

    play = () => {
        const getContext = () => ({...this.state.context});
        const updateContext = (key, value) => this.setState((prev) => ({
            context: {...prev.context, [key]: value},
        }));
        const askQuestion = (attribute, options) => {
            this.setState({attribute, options});
            return new Promise((resolve) => {
                this.resolve = resolve;
            });
        };
        const handleFinish = () => this.setState({finish: true});
        const log = rule => this.setState({logs: this.state.logs.concat(rule)});

        const ie = new InferenceEngine(getContext, updateContext, askQuestion, handleFinish, log);
        ie.start();
    };

    initState = () => this.setState({
        attribute: null,
        options: null,
        context: {},
        logs: [],
        finish: false,
    }, this.play);

    handleSelect = value => this.resolve(value);

    render() {
        const {
            attribute, options, finish, context, logs,
        } = this.state;
        const result = context[mainTarget];

        if (finish) {
            return (
                <Container flued className="d-flex flex-column align-items-center">
                    <Finish dinosaur={result}/>
                    <Button onClick={this.initState} variant="primary">Try Again</Button>
                </Container>
            );
        }

        return (
            <div className="container has-text-centered">
                {!attribute && (
                    <h2 className="title">Loading...</h2>
                )}
                {attribute && (
                    <Select
                        attribute={attribute}
                        options={options}
                        onChange={this.handleSelect}
                    />)}
                {logs && (
                    <KnowledgeBase rules={logs}/>
                )}
            </div>
        );
    }
}

export default GamePage;