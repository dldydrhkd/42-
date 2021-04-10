# MiniRT



### 1. Rendering

- 컴퓨터 그래픽스나 디지털 애니메이션으로 가상으로 완성된 결과를 만들어 내는 과정 또는 완성된 화면이나 영상


### 2. Rasterization

- Vector graphics를 pixel pattern으로 변환하는 것

- 존재하는 모든 object에 좌표를 할당하고, transformation matrix들을 통해 움직이게 하는것

- 벡터 또는 윤곽선 데이터를 bitmap으로 바꾸는 과정

    <p>
        <img width="461" alt="스크린샷 2021-04-10 오후 3 55 21" src="https://user-images.githubusercontent.com/48857296/114261395-48b8e680-9a15-11eb-95fd-dbf9468deb4a.png">
    </p>

- 단점

    - 그림자와 반사, 투명한 물체의 표현이 불가능하다
    
    - 각각의 object들은 그걸 이루고 있는 수 많은 삼각형들은 서로를 신경 쓰지 않고 자기 색만 고집하는 있다는 것이다
    
    - 해결 방법 
        
        - texture
        
- Rasterization은 절대적인 효율성을 추구한다. 빠른 속도를 위해서는 최대한 많은 작업을 한꺼번에 처리할 수 있어야 하고, 각 pixel의 color를 결정하는 데 있어 dependency를 최대한으로 줄임으로써 그러한 연산을 가능하게 한다

- Texture

    - Texture를 통해 그림자를 못 만들면 그림자를 덮어 씌우고, 거울이 반사를 못하면 주위 환경을 그대로 찍어서 반사면에 붙여 넣게 한다
    
        <p>
            <img width="536" alt="스크린샷 2021-04-10 오후 3 58 36" src="https://user-images.githubusercontent.com/48857296/114261466-b533e580-9a15-11eb-9e0f-59dcd83b34e5.png">
        </p>

### 3. Ray Tracing

- Pysically-Based Model
    
- 현실 세계에서, 모든 시각적 효과에는 빛이 관여한다. 그래픽 광원에서 방출한 빛이 물체에서 반사하고, 굴절하고, 산란되는 특성을 최대한 비슷하게 모방하는 것이 Ray Tracing이다
    
    <p>
        <img width="634" alt="스크린샷 2021-04-10 오후 4 01 12" src="https://user-images.githubusercontent.com/48857296/114261544-080d9d00-9a16-11eb-9326-ce80128044f6.png">
    </p>

### 4. Rasterization vs Ray Tracing

- Rasterization과 Ray Tracing이 추가하는 목적은 같다. 꼭지점들로 이루어진 가상의 오브젝트를 눈에 보이는 픽셀로 옮기는 것이다
    

- Rasterization에서 Texture Mapping으로 하는 여러 가지 advanced effect들을 Ray Tracing에서는 secondary ray, 즉 추가적인 빛을 casting함으로써 비교적 자연스럽게 구현될 수 있다

- 실제로 Shadow가 만들어지고 transparent, mirror-like한 물체들의 표현은 그러한 간접광들에 의해 발생하는 것이기 때문이다.

    <p>
        <img width="508" alt="스크린샷 2021-04-10 오후 4 08 39" src="https://user-images.githubusercontent.com/48857296/114261717-101a0c80-9a17-11eb-82b0-2fcca63394d3.png">
    </p>

- 그러므로 기본적으로 Ray Tracing에서 조명에 대한 것은 global illumination으로 처리된다

- Ray와 Object 교차점(intersection point)에서 계산된 shading은 이 표면에서 발생한 반사광에 비친 또 다른 표면의 shading에도 영향을 미치는 것이다.
