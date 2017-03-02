/*  fwdmodel_dwi.h - Implements the GRASE model

    Jesper Kallehauge, IBME

    Copyright (C) 2007-2016 University of Oxford  */

/*  CCOPYRIGHT */

#include "fabber_core/fwdmodel.h"
#include "fabber_core/rundata.h"

#include <newmat.h>

#include <string>
#include <vector>

class DWIFwdModel : public FwdModel
{
public:
    static FwdModel *NewInstance();

    void GetOptions(std::vector<OptionSpec> &opts) const;
    std::string GetDescription() const;
    virtual std::vector<std::string> GetUsage() const;
    virtual std::string ModelVersion() const;

    // Virtual function overrides
    virtual void Initialize(ArgsType &args);
    virtual void Evaluate(const NEWMAT::ColumnVector &params,
        NEWMAT::ColumnVector &result) const;

    virtual void NameParams(std::vector<std::string> &names) const;
    virtual int NumParams() const
    {
        return 2;
    }

    virtual void HardcodedInitialDists(MVNDist &prior, MVNDist &posterior) const;

protected:
    // Constants

    // Lookup the starting indices of the parameters
    int ADC_index() const { return 1; }
    int sig0_index() const { return 2; }
    //for ARD
    std::vector<int> ard_index;

    bool doard;
    NEWMAT::ColumnVector bvals;

private:
    /** Auto-register with forward model factory. */
    static FactoryRegistration<FwdModelFactory, DWIFwdModel> registration;
};