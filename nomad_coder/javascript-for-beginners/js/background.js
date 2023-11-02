const bgImgArr = [
    "0.jpg",
    "1.jpg",
    "2.jpg",
    "3.jpg",
];
let randomBgImg = bgImgArr[Math.floor(Math.random() * bgImgArr.length)];

// make image element
let bgImgElement = document.createElement("img");
bgImgElement.src = `img/${randomBgImg}`;

document.body.appendChild(bgImgElement);