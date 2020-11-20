import rawRules from './rules.json';
import attributes from './attributes.json';
import icons from './icons.json';

const rules = rawRules.map((rule, i) => ({...rule, id: i + 1}));
export {attributes, rules, icons};
