import { Router, Request, Response } from 'express';
import path from 'path'

const uiRouter: Router = Router();

// Server root route
uiRouter.get("/", (req: Request, res: Response) => {
	res.sendFile(path.join(__dirname, "./public/index.html"));
});

//
export { uiRouter };