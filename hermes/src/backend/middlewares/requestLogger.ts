import { Request, Response, NextFunction } from 'express';
import fs from 'fs';


export function requestLogger(req: Request, res: Response, next: NextFunction) {
    const { ip, method, url, body } = req;
    let logData = `[${new Date().toISOString()}] ${ip} => ${method}: ${url} ${JSON.stringify(body)}\n`
    logData = logData.split("{}").join("");  // Croyez le ou non, cette ligne supprime les objets vides ({}) parce la fonction replace ne remplace qu'une seule occurence pour des raisons qui mes sont obscures...

    // Write the request in the log file
    fs.appendFile("./logs/requests.log", logData, (err) => {
        if (err) {
            console.error(`Failed to write to request log: ${err}`);
        }
    });

    next();
}
