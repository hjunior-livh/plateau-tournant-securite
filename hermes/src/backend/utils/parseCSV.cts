import * as fs from 'fs';


export function parseCSV(filePath: string): Promise<string[][]> {
    return new Promise<string[][]>((resolve, reject) => {
        const rows: string[][] = [];

        fs.readFile(filePath, 'utf8', (err, data) => {
            if (err) {
                reject(err);
                return;
            }

            const lines = data.trim().split('\n');
            for (const line of lines) {
                const columns = line.split(',');
                rows.push(columns);
            }

            resolve(rows);
        });
    });
}