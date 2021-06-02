# Voyager-game

## Описание

### Немного лора
<p style='text-align: justify;'>
В отдалённом будущем, когда человечество уже во всю бороздило космическое пространство, 
несколько исследователей попали на небольшую систему на окраине вселенной. Попав в эту систему, герои устремились к её звезде, 
дабы восполнить топливо для двигателей, но к их удивлению и разочарованию звезда этой системы оказалась потухшей.
Их корабль завис на орбите данной звезды. Они пролетели очень большое расстояние, чтобы найти необычный источник энергии:
некий материал, который при определённых условиях даёт огромное количество энергии. По расчётам героев, его бы хватило, чтобы
совершить гипер-прыжок на орбиту звезды соседней планеты и для зарядки всех батарей.
</p>

<p style='text-align: justify;'>
По старым записям, с затерянным источником, герои выяснили, что данный материал предоставит такой объём энергии только при условии,
что он пролетел через любую системы от её звезды, до её пределов, пролетев около каждой из планет данной системы.
</p>

<p style='text-align: justify;'>
Странное условие и мифичность существования данного материала смущало героев, но в текущей ситуации этот материал, 
был единственной возможностью для возвращения домой. Спустившись на первую планету этой системы, в разноцветной каменной пещере
герои нашли этот материал: маленький полупрозрачный камешек, с чем-то чёрным, заключённым в золотистое вращающееся неоднородное кольцо.
Камень завораживал, и был необычайно тяжёлым для кусочка размером с монетку.Герои, забрав его, отправились на корабль, и, потратив остатки основного топлива, 
вернулись на орбиту звезды. Следующие несколько дней они провели в поисках способа выбраться из этой системы.
</p>

<p style='text-align: justify;'>
Через несколько дней, один из учёных вспомнил о явлении гравитационного манёвра, которым пользовались раньше, когда ещё не появились гипер-прыжки, 
и топливо занимало большую часть космического аппарата. Данное явление позволяет добавить энергию кораблю без включения его двигателей.
Своим осенением герой поделился с остальным экипажем и они решили воспользоваться этим, дабы выбраться за пределы этой системы на остатках их топлива.
</p>

<p style='text-align: justify;'>
Как ни странно это явление позволит героям не только выбраться за пределы системы, но и при удачных манёврах выполнить условия того необычного материала, 
с помощью которого они и смогут достичь соседней системы и пополнить запасы топлива и электричества.
</p>

**Их путешествие только начинается...**

### А теперь к игре

<p style='text-align: justify;'>
Это игра основанная на физической симуляции движения в космическом пространстве,
а также на связанном с ней и ранее названном явлении - гравитационный манёвр. Игрок получает в управление корабль учёных.
Ему поставлена задача - добраться до дома. Для этого нужно пролететь через все системы, "посетив" все планеты каждой системы. 
Уровень - это одна из систем, которую посетят герои по пути домой.
</p>

## Суть геймплея

<p style='text-align: justify;'>
Игрок получает в управление корабль, оказавшийся на орбите звезды в далёкой звёздной системе.
У игрока есть возможность поворачивать корабль вокруг своей оси с помощью кнопок A и D, а также ускорять 
его вперёд или назад кнопками W и S. Как и было сказано ранее его цель - управляя кораблём добраться до дома. Для этого нужно вылететь 
за пределы всех систем (пройти все уровни)  и "посетить" все планеты. 
</p>

<p style='text-align: justify;'>
Под "посетить" понимается пролёт около планеты на определённом расстоянии, заданном некоторой орбитой вокруг это планеты.
Пролётом считается нахождение корабля в любой точке внутри этой орбиты.
</p>

<p style='text-align: justify;'>
Также у корабля есть топливо, которое тратится когда игрок пытается ускориться или замедлиться, если топливо
заканчивается, то игра тоже считается законченной.
</p>

Помимо топлива, есть батарея, которая отвечает за работу всей электроники. 
Её заряд кончается по мере прохождения уровня.
В случае если она закончится, игрок проигрывает.

### Установка

Для установки данной игры необходимо скачать всей файлы из данного репозитория.

Можно его скачать следующей командой:

``` 
git clone https://gitlab.com/Flash1e/voyager-game
```

Далее следует зайти в корневую директорию скачанного проекта и подключить дополнительные модули:

``` 
git submodule init
git submodule update 
```

После чего следует создать папку build:

``` 
mkdir build
```

И собрать игру командами:

``` 
cmake  ./build
make ./build
```

Для того чтобы поиграть, достаточно написать:

```
./build/voyager
```

Или вручную зайти в папку build и запустить файл voyager


## Авторы

- ***Дмитрий Варин*** — ответственный за логику игры
- ***Владимир Ларин*** — ответственный за графику, меню и события
- ***Артем Ветошкин*** — ответственный за физику, математику и состояния игры

*Хорошей игры!*  
*Да пребудет с вами сила*


## Послесловие

Данная игра является проектом, выполненным в ходе прохождения курса Углублённое программирование на С++ в Технопарке Mail.ru МГТУ им. Баумана

## Контакты

- ***Дмитрий Варин*** — [Telegram](https://t.me/varindv), [GitHub](https://github.com/Flash1ee), [GitLab](https://gitlab.com/Flash1e)
- ***Владимир Ларин*** — [Telegram](https://t.me/volodyalarin), [GitHub](https://github.com/volodyalarin), [GitLab](https://gitlab.com/volodyalarin)
- ***Артем Ветошкин*** — [Telegram](https://t.me/TheCompilerA), [GitHub](https://github.com/ThCompiler), [GitLab](https://gitlab.com/TheCompiler)
