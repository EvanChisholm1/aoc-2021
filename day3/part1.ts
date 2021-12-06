const file = await Deno.readTextFile("./input.txt");

const positions: {
  [key: string]: number[];
} = {};

const numList = file.split("\n");

for (const binString of numList) {
  binString.split("").forEach((num, i) => {
    if (!positions[i]) {
      positions[i] = [];
    }
    positions[i].push(parseInt(num));
  });
}

const talliedPositions: {
  [key: string]: {
    zero: number;
    one: number;
  };
} = {};

for (const key of Object.keys(positions)) {
  const talliedPos = {
    zero: 0,
    one: 0,
  };
  positions[key].forEach(num => {
    if (num === 1) {
      talliedPos.one += 1;
    } else {
      talliedPos.zero += 1;
    }
  });

  talliedPositions[key] = talliedPos;
}

const gamma = parseInt(
  Object.keys(talliedPositions)
    .map(key => talliedPositions[key])
    .map(tally => (tally.one > tally.zero ? 1 : 0))
    .join(""),
  2
);

const epsilon = parseInt(
  Object.keys(talliedPositions)
    .map(key => talliedPositions[key])
    .map(tally => (tally.one > tally.zero ? 0 : 1))
    .join(""),
  2
);

console.log(gamma * epsilon);
