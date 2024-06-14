/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "openSettings",
    "",
    "on_pause_button_clicked",
    "on_restart_button_clicked",
    "on_listWidget_currentRowChanged",
    "currentRow",
    "updateList",
    "curTime",
    "getData",
    "filename",
    "on_open_button_clicked",
    "setLogFile",
    "size",
    "on_left_button_clicked",
    "on_right_button_clicked",
    "on_paths_button_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[24];
    char stringdata4[26];
    char stringdata5[32];
    char stringdata6[11];
    char stringdata7[11];
    char stringdata8[8];
    char stringdata9[8];
    char stringdata10[9];
    char stringdata11[23];
    char stringdata12[11];
    char stringdata13[5];
    char stringdata14[23];
    char stringdata15[24];
    char stringdata16[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 12),  // "openSettings"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 23),  // "on_pause_button_clicked"
        QT_MOC_LITERAL(49, 25),  // "on_restart_button_clicked"
        QT_MOC_LITERAL(75, 31),  // "on_listWidget_currentRowChanged"
        QT_MOC_LITERAL(107, 10),  // "currentRow"
        QT_MOC_LITERAL(118, 10),  // "updateList"
        QT_MOC_LITERAL(129, 7),  // "curTime"
        QT_MOC_LITERAL(137, 7),  // "getData"
        QT_MOC_LITERAL(145, 8),  // "filename"
        QT_MOC_LITERAL(154, 22),  // "on_open_button_clicked"
        QT_MOC_LITERAL(177, 10),  // "setLogFile"
        QT_MOC_LITERAL(188, 4),  // "size"
        QT_MOC_LITERAL(193, 22),  // "on_left_button_clicked"
        QT_MOC_LITERAL(216, 23),  // "on_right_button_clicked"
        QT_MOC_LITERAL(240, 23)   // "on_paths_button_clicked"
    },
    "MainWindow",
    "openSettings",
    "",
    "on_pause_button_clicked",
    "on_restart_button_clicked",
    "on_listWidget_currentRowChanged",
    "currentRow",
    "updateList",
    "curTime",
    "getData",
    "filename",
    "on_open_button_clicked",
    "setLogFile",
    "size",
    "on_left_button_clicked",
    "on_right_button_clicked",
    "on_paths_button_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   81,    2, 0x08,    2 /* Private */,
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    1,   83,    2, 0x08,    4 /* Private */,
       7,    1,   86,    2, 0x08,    6 /* Private */,
       9,    1,   89,    2, 0x08,    8 /* Private */,
      11,    0,   92,    2, 0x08,   10 /* Private */,
      12,    2,   93,    2, 0x08,   11 /* Private */,
      14,    0,   98,    2, 0x08,   14 /* Private */,
      15,    0,   99,    2, 0x08,   15 /* Private */,
      16,    0,  100,    2, 0x08,   16 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Bool, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   10,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'openSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pause_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_restart_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_listWidget_currentRowChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getData'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_open_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setLogFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_left_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_right_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_paths_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openSettings(); break;
        case 1: _t->on_pause_button_clicked(); break;
        case 2: _t->on_restart_button_clicked(); break;
        case 3: _t->on_listWidget_currentRowChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->updateList((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: { bool _r = _t->getData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->on_open_button_clicked(); break;
        case 7: _t->setLogFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 8: _t->on_left_button_clicked(); break;
        case 9: _t->on_right_button_clicked(); break;
        case 10: _t->on_paths_button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::openSettings; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::openSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
