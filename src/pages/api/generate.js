// Next.js API route support: https://nextjs.org/docs/api-routes/introduction
import ffi from '@xingrz/ffi-napi'
import cors from 'cors'
import nextConnect from 'next-connect'

const handler = nextConnect({
  onNoMatch: (req, res) => {
    res.status(404).end('Resource not found!')
  },
  onError: (err, req, res, next) => {
    console.error(err.stack)
    res.status(500).end('Something broke!')
  }
})
  .use(cors())
  .post((req, res) => {
    const { NumeroSocial, RIF, NIT, Marca = 'Bematech' } = req.body

    const lib = new ffi.Library('../../BemaLacra/Release/BemaLacra.dll', {
      'GenerarSena': ['int', ['string', 'string', 'string', 'string']]
    })

    const generatedKey = lib.GenerarSena(
      convertString(NumeroSocial),
      converString(MARCA),
      convertString(RIF),
      convertString(NIT)
    )
    console.log(generatedKey)

    return res.status(200).json({ key: generatedKey, data: new Date() })
  })
  .get((req, res) => {
    const { n1, n2 } = req.body

    const lib = new ffi.Library('./teste', {
      'GenerarSena': ['int', ['string', 'string', 'string', 'string']]
    })

    const generatedKey = lib.soma(n1, n2)
    console.log(generatedKey)

    return res.status(200).json({ key: generatedKey, data: new Date() })
  })

export default handler