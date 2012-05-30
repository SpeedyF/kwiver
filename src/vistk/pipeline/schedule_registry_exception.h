/*ckwg +5
 * Copyright 2011-2012 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef VISTK_PIPELINE_SCHEDULE_REGISTRY_EXCEPTION_H
#define VISTK_PIPELINE_SCHEDULE_REGISTRY_EXCEPTION_H

#include "pipeline-config.h"

#include "schedule_registry.h"
#include "types.h"

/**
 * \file schedule_registry_exception.h
 *
 * \brief Header for exceptions used within the \link vistk::schedule_registry schedule registry\endlink.
 */

namespace vistk
{

/**
 * \class schedule_registry_exception schedule_registry_exception.h <vistk/pipeline/schedule_registry_exception.h>
 *
 * \brief The base class for all exceptions thrown from a \ref schedule_registry.
 *
 * \ingroup exceptions
 */
class VISTK_PIPELINE_EXPORT schedule_registry_exception
  : public pipeline_exception
{
};

/**
 * \class null_schedule_ctor_exception schedule_registry_exception.h <vistk/pipeline/schedule_registry_exception.h>
 *
 * \brief Thrown when a \c NULL constructor function is added to the registry.
 *
 * \ingroup exceptions
 */
class VISTK_PIPELINE_EXPORT null_schedule_ctor_exception
  : public schedule_registry_exception
{
  public:
    /**
     * \brief Constructor.
     *
     * \param type The type the ctor is for.
     */
    null_schedule_ctor_exception(schedule_registry::type_t const& type) throw();
    /**
     * \brief Destructor.
     */
    ~null_schedule_ctor_exception() throw();

    /// The type that was passed a \c NULL constructor.
    schedule_registry::type_t const m_type;
};

/**
 * \class null_schedule_registry_config_exception schedule_registry_exception.h <vistk/pipeline/schedule_registry_exception.h>
 *
 * \brief Thrown when a \c NULL \ref config is passed to a schedule.
 *
 * \ingroup exceptions
 */
class VISTK_PIPELINE_EXPORT null_schedule_registry_config_exception
  : public schedule_registry_exception
{
  public:
    /**
     * \brief Constructor.
     */
    null_schedule_registry_config_exception() throw();
    /**
     * \brief Destructor.
     */
    ~null_schedule_registry_config_exception() throw();
};

/**
 * \class null_schedule_registry_pipeline_exception schedule_registry_exception.h <vistk/pipeline/schedule_registry_exception.h>
 *
 * \brief Thrown when a \c NULL \link vistk::pipeline\endlink is passed to a schedule.
 *
 * \ingroup exceptions
 */
class VISTK_PIPELINE_EXPORT null_schedule_registry_pipeline_exception
  : public schedule_registry_exception
{
  public:
    /**
     * \brief Constructor.
     */
    null_schedule_registry_pipeline_exception() throw();
    /**
     * \brief Destructor.
     */
    ~null_schedule_registry_pipeline_exception() throw();
};

/**
 * \class no_such_schedule_type_exception schedule_registry_exception.h <vistk/pipeline/schedule_registry_exception.h>
 *
 * \brief Thrown when a type is requested, but does not exist in the registry.
 *
 * \ingroup exceptions
 */
class VISTK_PIPELINE_EXPORT no_such_schedule_type_exception
  : public schedule_registry_exception
{
  public:
    /**
     * \brief Constructor.
     *
     * \param type The type requested.
     */
    no_such_schedule_type_exception(schedule_registry::type_t const& type) throw();
    /**
     * \brief Destructor.
     */
    ~no_such_schedule_type_exception() throw();

    /// The type that was requested from the \link schedule_registry schedule registry\endlink.
    schedule_registry::type_t const m_type;
};

/**
 * \class schedule_type_already_exists_exception schedule_registry_exception.h <vistk/pipeline/schedule_registry_exception.h>
 *
 * \brief Thrown when a type is added, but does already exists in the registry.
 *
 * \ingroup exceptions
 */
class VISTK_PIPELINE_EXPORT schedule_type_already_exists_exception
  : public schedule_registry_exception
{
  public:
    /**
     * \brief Constructor.
     *
     * \param type The type requested.
     */
    schedule_type_already_exists_exception(schedule_registry::type_t const& type) throw();
    /**
     * \brief Destructor.
     */
    ~schedule_type_already_exists_exception() throw();

    /// The type that was requested from the \link schedule_registry schedule registry\endlink.
    schedule_registry::type_t const m_type;
};

}

#endif // VISTK_PIPELINE_SCHEDULE_REGISTRY_EXCEPTION_H
