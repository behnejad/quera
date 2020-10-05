export default function generateTree() {
  let tree = {
    0: {
      id: 0,
      counter: 0,
      name: "file 0",
      childIds: [],
      isDir: false
    }
  }

  for (let i = 1; i < 20; i++) {
    let parentId = Math.floor(Math.pow(Math.random(), 2) * i)
    tree[i] = {
      id: i,
      name: `file ${i}`,
      content: '',
      childIds: [],
      isDir: false
    }
    tree[parentId].childIds.push(i);
    tree[parentId].isDir = true;
    tree[parentId].name = `folder ${tree[parentId].id}`;
  }

  return tree
}
