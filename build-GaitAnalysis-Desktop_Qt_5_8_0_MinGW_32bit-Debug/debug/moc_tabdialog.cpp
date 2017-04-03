/****************************************************************************
** Meta object code from reading C++ file 'tabdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GaitAnalysis/tabdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ResultsTab_t {
    QByteArrayData data[4];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ResultsTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ResultsTab_t qt_meta_stringdata_ResultsTab = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ResultsTab"
QT_MOC_LITERAL(1, 11, 10), // "selectFile"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8) // "plotFile"

    },
    "ResultsTab\0selectFile\0\0plotFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResultsTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ResultsTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ResultsTab *_t = static_cast<ResultsTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectFile(); break;
        case 1: _t->plotFile(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ResultsTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ResultsTab.data,
      qt_meta_data_ResultsTab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ResultsTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResultsTab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ResultsTab.stringdata0))
        return static_cast<void*>(const_cast< ResultsTab*>(this));
    return QWidget::qt_metacast(_clname);
}

int ResultsTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_TimeSeriesTab_t {
    QByteArrayData data[4];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimeSeriesTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimeSeriesTab_t qt_meta_stringdata_TimeSeriesTab = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TimeSeriesTab"
QT_MOC_LITERAL(1, 14, 10), // "selectFile"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8) // "plotFile"

    },
    "TimeSeriesTab\0selectFile\0\0plotFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimeSeriesTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    0,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TimeSeriesTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimeSeriesTab *_t = static_cast<TimeSeriesTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectFile(); break;
        case 1: _t->plotFile(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TimeSeriesTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TimeSeriesTab.data,
      qt_meta_data_TimeSeriesTab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimeSeriesTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimeSeriesTab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimeSeriesTab.stringdata0))
        return static_cast<void*>(const_cast< TimeSeriesTab*>(this));
    return QWidget::qt_metacast(_clname);
}

int TimeSeriesTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_InputTab_t {
    QByteArrayData data[3];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InputTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InputTab_t qt_meta_stringdata_InputTab = {
    {
QT_MOC_LITERAL(0, 0, 8), // "InputTab"
QT_MOC_LITERAL(1, 9, 10), // "selectFile"
QT_MOC_LITERAL(2, 20, 0) // ""

    },
    "InputTab\0selectFile\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InputTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void InputTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InputTab *_t = static_cast<InputTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectFile(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject InputTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InputTab.data,
      qt_meta_data_InputTab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *InputTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InputTab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_InputTab.stringdata0))
        return static_cast<void*>(const_cast< InputTab*>(this));
    return QWidget::qt_metacast(_clname);
}

int InputTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_FrequentPatternTab_t {
    QByteArrayData data[1];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrequentPatternTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrequentPatternTab_t qt_meta_stringdata_FrequentPatternTab = {
    {
QT_MOC_LITERAL(0, 0, 18) // "FrequentPatternTab"

    },
    "FrequentPatternTab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrequentPatternTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void FrequentPatternTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject FrequentPatternTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FrequentPatternTab.data,
      qt_meta_data_FrequentPatternTab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FrequentPatternTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrequentPatternTab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FrequentPatternTab.stringdata0))
        return static_cast<void*>(const_cast< FrequentPatternTab*>(this));
    return QWidget::qt_metacast(_clname);
}

int FrequentPatternTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_FeatureBasedTab_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FeatureBasedTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FeatureBasedTab_t qt_meta_stringdata_FeatureBasedTab = {
    {
QT_MOC_LITERAL(0, 0, 15) // "FeatureBasedTab"

    },
    "FeatureBasedTab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FeatureBasedTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void FeatureBasedTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject FeatureBasedTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FeatureBasedTab.data,
      qt_meta_data_FeatureBasedTab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FeatureBasedTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FeatureBasedTab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FeatureBasedTab.stringdata0))
        return static_cast<void*>(const_cast< FeatureBasedTab*>(this));
    return QWidget::qt_metacast(_clname);
}

int FeatureBasedTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_TabDialog_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TabDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TabDialog_t qt_meta_stringdata_TabDialog = {
    {
QT_MOC_LITERAL(0, 0, 9) // "TabDialog"

    },
    "TabDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void TabDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject TabDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TabDialog.data,
      qt_meta_data_TabDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TabDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TabDialog.stringdata0))
        return static_cast<void*>(const_cast< TabDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int TabDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
