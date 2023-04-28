import express, { Express } from 'express'
import { requestLogger } from './middlewares/requestLogger';
import { uiRouter } from './routers/ui'
import { apiRouter } from './routers/api'


// Declaration of variables
const app: Express = express();
const port: number = 3000;


// Add third-party middleware
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(requestLogger);
app.use("/", express.static("./build/public"));
app.use("/", uiRouter);
app.use("/api", apiRouter);


// Server launch
app.listen(port, () => {
	console.log(`[i] Hermes server launched: http://localhost:${port}`);
}); 