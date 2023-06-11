import * as fs from 'fs';


export function parseCSV(filePath: string): Promise<string[]> {
    return new Promise<string[]>((resolve, reject) => {
        let rows: string[] = [];

        fs.readFile(`./data/${filePath}`, 'utf8', (err, data) => {
            if (err) {
                reject(err);
                return;
            }

            rows = data.trim().split('\n');
            resolve(rows);
        });
    });
}