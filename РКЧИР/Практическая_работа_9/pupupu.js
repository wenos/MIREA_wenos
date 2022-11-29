// const btn = document.querySelector('.like');
// const i = btn.querySelector('.fa-heart');
// const body = document.querySelector('.sqr');
//
// btn.addEventListener("click", () => {
//     if (i.classList.contains('fa-regular')) {
//         i.classList.remove('fa-regular');
//         i.classList.add('fa-solid');
//         body.addEventListener('mousemove', drawHeartOnPos);
//     } else{
//         i.classList.remove('fa-solid');
//         i.classList.add('fa-regular');
//         body.removeEventListener('mousemove', drawHeartOnPos);
//     }
// });
//
// function drawHeartOnPos(event) {
//     const heart = document.createElement("i");
//     heart.className = 'fa-solid fa-heart';
//     heart.style.position="absolute";
//     heart.style.top = (event.pageY - 10) + "px";
//     heart.style.left = (event.pageX + 10) + "px"
//     document.body.append(heart);
//     setTimeout(function() {
//         document.body.removeChild(heart);
//     }, 500);
// }
// let a = document.querySelector(".content_latex button");
// b = a.innerHTML.length;
// a.style.width = b * 10 + "px";


function parsing() {
    let text = document.querySelector(".frame-latex .input-box textarea");
    let pars = text.value;
    let out = document.querySelector(".frame-latex .output-box")
    let s = "";
    let newNotif = document.createElement("div");
    out.append(newNotif);
    newNotif.innerHTML = "$$a = {F \over m}$$";

    // newNotif.innerHTML = "$$x_1,_2 = {-b \\pm \\sqrt{b^2-4ac} \\over 2a}$$";
    // for (let i = 0; i < pars.length; ++i) {
    //     if ( pars[i] !== '{' && pars[i] !== '}' ) {
    //         console.log(s);
    //         s += pars[i];
    //     } else if (pars[i] === '{') {
    //         s = "";
    //         console.log(s);
    //     } else {
    //         console.log(s);
    //         out.innerHTML += " " + s;
    //     }
    // }
}















