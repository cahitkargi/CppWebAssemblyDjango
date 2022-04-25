
#include <math.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>

EM_JS(void, drawCircle, (float x, float y, float r), {
    const canvas = document.querySelector('canvas');
    const context = canvas.getContext('2d');
    context.fillStyle = '#28d6fc';
    context.beginPath();
    context.arc(x, y, r, 0, 2 * Math.PI);
    context.fill();
})

EM_JS(void, clearCanvas, (), {
    const canvas = document.querySelector('canvas');
    const context = canvas.getContext('2d');
    context.clearRect(0, 0, canvas.width, canvas.height)
})

static float t{0};
extern "C" {
EMSCRIPTEN_KEEPALIVE void update(){
    static float dt = 1.0f / 60.0f;
    clearCanvas();
    drawCircle(500+(sin(t) * 450), 500-(sin(t*2) * 200), 50.0);
    t += dt;
}

EMSCRIPTEN_KEEPALIVE
int fib(int n) {
    int i, t, a = 0, b = 1;
    for(i = 0; i < n; ++i){
        t = a + b;
        a = b;
        b = t;
    }
    return b;
    }
}
#endif


int main(){
    return 0;
}
