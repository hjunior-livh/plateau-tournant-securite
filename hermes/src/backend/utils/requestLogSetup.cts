import fs from 'fs';

export function setupLogging() {
    try {
        if (!fs.existsSync("./logs")) {
            fs.mkdirSync("./logs");
        }
    } catch (err) {
        console.error(err);
    }
}