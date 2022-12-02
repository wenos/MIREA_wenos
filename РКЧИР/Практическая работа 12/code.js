const content = document.querySelector(".list");

newLi();

function newLi() {
    let b = document.querySelector(".list")
    // if (b) {
    //     let a = prompt("Введите элемент списка");
    //     let newNotif = document.createElement("li");
    //     content.append(newNotif);
    //     newNotif.innerHTML = b;
    //     newLi();
    // }
    while (true) {
        let data = prompt("Введите текст для элемента списка", "");
        if (!data) {
            break;
        }
        let li = document.createElement('li');
        li.textContent = data;
ч
    }
}
//
// // showNotification();
// //
// // function showNotification({top = 0, right = 0, className, html}) {
// //
// //     let notification = document.createElement('div');
// //     notification.className = "notification";
// //     if (className) {
// //         notification.classList.add(className);
// //     }
// //
// //     notification.style.top = top + 'px';
// //     notification.style.right = right + 'px';
// //
// //     notification.innerHTML = html;
// //     document.body.append(notification);
// //
// //     setTimeout(() => notification.remove(), 1500);
// // }
// //
// // // test it
// // let i = 1;
// // setInterval(() => {
// //     showNotification({
// //         top: 10,
// //         right: 10,
// //         html: 'Hello ' + i++,
// //         className: "welcome"
// //     });
// // }, 2000);

let notifSection = document.querySelector(".notification-section");

function showNotification() {
    let div = document.createElement("div");
    div.className = "notification";

    notifSection.append(div);

    div.textContent = "Письмецо пришло";

    let closeBtn = document.createElement("button");
    closeBtn.innerHTML = "X";
    closeBtn.className = "close-btn";
    div.append(closeBtn);
    setTimeout(function () {
        div.remove();
    }, 5000);
}

setInterval(() => {
    showNotification({
    });
}, 2000)

var block = document.querySelector(".notification-section");

block.onclick = function (event) {
    let notification = event.target.closest(".close-btn");
    notification.parentElement.remove();
};


let img = document.querySelector(".bl img");
let imgBlock = document.querySelector(".bl");

function imageToCenter(img) {
    img.style.left = (img.parentElement.clientWidth - img.clientWidth) / 2 + "px";
    img.style.top =
        (img.parentElement.clientHeight - img.clientHeight) / 2 + "px";
}

imageToCenter(img);



imgBlock.onclick = function (e) {
    x = e.clientX - imgBlock.offsetLeft;
    y = e.clientY - imgBlock.offsetTop;
    alert("X: " + x + "\n" + "Y: " + y);
};

// changeImgSize.onclick = function () {
//     cords = inputImgSize.value.split(" ");
//     if (cords.length == 2) {
//         img.style = `
//     width: ${cords[0]}px;
//     height: ${cords[1]}px`;
//         imageToCenter(img);
//         inputImgSize.value = "";
//     } else {
//         alert("Неверный формат данных");
//     }
// };
//
// changeAreaSize.onclick = function () {
//     cords = inputAreaSize.value.split(" ");
//     if (cords.length == 2) {
//         imgBlock.style = `
//     width: ${cords[0]}px;
//     height: ${cords[1]}px`;
//         imageToCenter(img);
//         inputAreaSize.value = "";
//     } else {
//         alert("Неверный формат данных");
//     }
// };

// imageToCenter(img);