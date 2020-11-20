import React, {Fragment} from 'react';

import {icons} from 'data';
import Image from "react-bootstrap/Image";

const Finish = ({dinosaur}) => (
    <Fragment>
        <h2>{dinosaur ? `it's ${dinosaur}!` : 'Sorry, can\'t identify dinosaur'}</h2>
        {dinosaur && <Image className="m-2" src={icons[dinosaur]}/>}
    </Fragment>
);

export default Finish;