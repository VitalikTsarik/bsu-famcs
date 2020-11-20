import React from 'react';
import ListGroup from "react-bootstrap/ListGroup";
import Container from "react-bootstrap/Container";
import Image from "react-bootstrap/Image";

import {icons} from 'data';

const Select = ({attribute, options, onChange}) => {
    const handleClick = (e) => onChange(e.target.value)
    return (
        <Container fluid>
            <h2 className="row justify-content-center">Choose {attribute} of dinosaur</h2>
            <ListGroup className="row-cols-md-2 align-items-center">
                {options.map(value => (
                    <ListGroup.Item
                        key={value}
                        variant="primary"
                        action
                        as="button"
                        value={value}
                        onClick={handleClick}
                        className="select"
                    >
                        {value}
                        <Image src={icons[value]} className="selectIcon"/>
                    </ListGroup.Item>
                ))}
            </ListGroup>
        </Container>
    );
};

export default Select;
