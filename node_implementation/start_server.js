import AircacheServer from './index.js';

const {AIRCACHE_PORT : port} = process.env;

const server = new AircacheServer({port});

server.start();
