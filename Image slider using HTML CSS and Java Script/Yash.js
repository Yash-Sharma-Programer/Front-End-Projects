var nextBtn = document.querySelector('.next'),
    prevBtn = document.querySelector('.prev'),
    carousel = document.querySelector('.carousel'),
    list = document.querySelector('.list'),
    item = document.querySelectorAll('.item'),
    runningTime = document.querySelector('.carousel .timeRunning');

let timeRunning = 3000;
let timeAutoNext = 7000;

let runTimeOut;
let runNextAuto = setTimeout(() => {
    nextBtn.click();
}, timeAutoNext);


// RESET TIME ANIMATION FOR SLIDER
function resetTimeAnimation() {
    runningTime.style.animation = 'none';
    runningTime.offsetHeight; // force reflow
    runningTime.style.animation = null;
    runningTime.style.animation = 'runningTime 7s linear 1 forwards';
}


// SLIDER FUNCTION
function showSlider(type) {
    let sliderItemsDom = list.querySelectorAll('.carousel .list .item');

    if (type === 'next') {
        list.appendChild(sliderItemsDom[0]);
        carousel.classList.add('next');
    } else {
        list.prepend(sliderItemsDom[sliderItemsDom.length - 1]);
        carousel.classList.add('prev');
    }

    clearTimeout(runTimeOut);
    runTimeOut = setTimeout(() => {
        carousel.classList.remove('next');
        carousel.classList.remove('prev');
    }, timeRunning);

    clearTimeout(runNextAuto);
    runNextAuto = setTimeout(() => {
        nextBtn.click();
    }, timeAutoNext);

    resetTimeAnimation();

    attachSubscribeEvents(); // re-attach subscribe events after slide change
}


// BUTTON CLICK CONTROLS
nextBtn.onclick = function () {
    showSlider('next');
};

prevBtn.onclick = function () {
    showSlider('prev');
};


// ATTACH SUBSCRIBE/UNSUBSCRIBE CLICK EVENTS
function attachSubscribeEvents() {
    const subButtons = document.querySelectorAll(".Sub");

    subButtons.forEach(btn => {
        btn.onclick = function () {
            if (btn.innerText.trim() === "Subscribe") {
                btn.innerText = "Unsubscribe";
                btn.classList.add("unsub");
            } else {
                btn.innerText = "Subscribe";
                btn.classList.remove("unsub");
            }
        };
    });
}


// INITIAL START
resetTimeAnimation();
attachSubscribeEvents();
